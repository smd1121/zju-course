#include <iostream>
#include <Windows.h>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

queue<int> cars;
HANDLE station1, station2, carArrival;
HANDLE queueSemaphore, stdoutSemaphore;

// set output color
void setColor(unsigned short fore = 7, unsigned short bg = 6) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fore | bg);
}

// output go to oil msg
void goToOil(int station, int car, int duration) {
	WaitForSingleObject(stdoutSemaphore, INFINITE);
	
	// abstract of beginning to oil
	setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
			 BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << "[B " << station << " " << car << "]";
	setColor();
	
	// beginning to oil
	cout << "Station #" << station << " is oiling car #" << car << "." << endl;
	
	ReleaseSemaphore(stdoutSemaphore, 1, NULL);
	
	// oiling duration
	Sleep(duration);
	
	WaitForSingleObject(stdoutSemaphore, INFINITE);
	
	// abstract of finishing to oil
	setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
			 BACKGROUND_INTENSITY | BACKGROUND_GREEN);
	cout << "[F " << station << " " << car << "]";
	setColor();
	
	// finishing to oil
	cout << "Station #" << station << " has finished oiling car #" << car << "." << endl;
	
	ReleaseSemaphore(stdoutSemaphore, 1, NULL);
}

// station thread handler
DWORD WINAPI station(LPVOID param) {
	int stationIndex = *((int *) param);
	int oiledCar = -1;
	srand(time(NULL));
	// run permantly
	while (true) {
		WaitForSingleObject(queueSemaphore, INFINITE);
		// get oiled car number
		if (!cars.empty()) {
			oiledCar = cars.front();
			cars.pop();
		}
		ReleaseSemaphore(queueSemaphore, 1, NULL);
		
		// oiling
		if (oiledCar != -1)
			goToOil(stationIndex, oiledCar, rand() % 2000 + 5000);
			
		oiledCar = -1;
	}
}

DWORD WINAPI arrival(LPVOID param) {
	srand(time(NULL));
	int nextArrival;
	int carIndex = 0;
	// run permanently
	while (true) {
		// wait a random duration for the next arrival
		nextArrival = rand() % 3000;
		Sleep(nextArrival);
		
		// next arrived car index
		++carIndex;
		
		WaitForSingleObject(queueSemaphore, INFINITE);
		WaitForSingleObject(stdoutSemaphore, INFINITE);
		// if queue size <= 5, the arriving car will begin to queue
		if (cars.size() <= 5) {
			cars.push(carIndex);
			
			// abstract of arriving car
			setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
			 		 BACKGROUND_RED | BACKGROUND_GREEN);
			cout << "[Q " << carIndex << "]";
			setColor();	
			
			// arriving car
			cout << "Car #" << carIndex << " arrived and began to queue." << endl;
		}
		// else, the car will leave
		else {
			// abstract of leaving car
			setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
			 		 BACKGROUND_RED);
			cout << "[L " << carIndex << "]";
			setColor();	
			
			// leaving car
			cout << "Car #" << carIndex << " arrived but left because the queue is too long." << endl;
		}
		// print current queue
		setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN, 6);
		cout << "Current queue [" << cars.size() << "]: ";
		int queueSize = cars.size();
		for (int i = 0; i < queueSize; i++) {
			cout << cars.front() << " ";
			cars.push(cars.front());
			cars.pop();
		}
		cout << endl;
		setColor();	
		
		ReleaseSemaphore(queueSemaphore, 1, NULL);
		ReleaseSemaphore(stdoutSemaphore, 1, NULL);
	}
}

int main() {
	queueSemaphore  = CreateSemaphore(NULL, 1, 1, NULL);
	stdoutSemaphore = CreateSemaphore(NULL, 1, 1, NULL);
	
	carArrival = CreateThread(NULL, 0, arrival, NULL, 0, NULL);
	int stationNum1 = 1;
	station1 = CreateThread(NULL, 0, station, &stationNum1, 0, NULL);  
	int stationNum2 = 2;
	station2 = CreateThread(NULL, 0, station, &stationNum2, 0, NULL);
	
	// for running threads
	while(true);
	
	return 0;
}
