在文件夹 exes 中：
	pdadd.exe：
		从 diary.in 中读入日记，替换掉重复日期，按日期顺序存入 diary.log 中
		输入格式：
			多组输入，每组输入以一行日期开始，格式为 yyyy.mm.dd ，此后多行为该组输入（日记）的内容，以单独的一行一个字符 '.' 或 EOF 结束。
			
	pdlist.exe:
		(A) 直接运行，按顺序将 diary.log 中的日记输出到 diary.out 中
		(B) 在命令行中输入 pdlist DATE1 DATE2 ，其中 DATE1 和 DATE2 为出现过的日期，按顺序将其中间的日记输出到 diary.out 中
		
	pdshow.exe:
		在命令行中输入 pdshow DATE ，如果 DATE 是出现过的日期，则将对应的日记输出到 diary.out 中
		
	pdremove.exe:
		在命令行中输入 pdremove DATE ，如果 DATE 是出现过的日期，则在 .log 中将对应的日记删除，返回 0；否则返回 -1

	test.bat 分 3 次测试了上述 4 个 .exe 的合计 5 个功能，具体是：
	(1) 运行 pdadd 读入日记，并将 2020.02.21 到 2020.04.25 的日记存入 diary.out
	(2) 将 2020.04.26 的日记存入 diary.out
	(3) 将 2020.04.26 的日记删除，并将（剩余的）所有日记存入 diary.out
	
	
在文件夹 src 中：
	是对应的源码。compile.bat 实现了它们的编译。