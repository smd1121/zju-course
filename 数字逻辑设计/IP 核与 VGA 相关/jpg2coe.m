clc;
clear all;
[filename, path] = uigetfile('*.jpg');
oriFilename = fullfile(path, filename);
RGB=imread(oriFilename);
R=RGB(:,:,1);
G=RGB(:,:,2);
B=RGB(:,:,3);
n = size(RGB, 1);
m = size(RGB, 2);
outdata=zeros(1,n * m);
for r = 1:n
	for c = 1:m
		outdata((r-1)*m+c)=bitshift(bitand(R(r,c),240),4)+bitshift(bitand(G(r,c),240),0)+bitshift(bitand(B(r,c),240),-4);
	end
end	
fid=fopen([filename(1:end-4), '.coe'],'w+');
fprintf(fid,'memory_initialization_radix=16;\nmemory_initialization_vector=\n');
for r = 1:n
	for c = 1:m
        if (r == n && c == m) 
            fprintf(fid, '%x%x%x;', bitand(B(r,c),240)/16, bitand(G(r,c),240)/16,bitand(R(r,c),240)/16);
        else
            fprintf(fid, '%x%x%x, ', bitand(B(r,c),240)/16, bitand(G(r,c),240)/16,bitand(R(r,c),240)/16);
        end
        if (c == m)
            fprintf(fid, '\n');
        end
	end
end	

fclose(fid);