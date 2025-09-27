# 42_exam_rank_04
My preparations and the finished task for the exam in the future

The subject that will be on the exam or very similar to it is in subject.en.txt.

I want to try to do it without using: malloc, free, signal, kill, strncmp.
	upd: I did it!

While I was preparing myself for the exam I decided to do it in a few stages, every time leveling up complexity. I suggest for you to do it as well. Everything becomes muuuuuch cleaner. Even if you did the execution part in minishell:
	---
	1. Build the simple microshell for one simple command:
		./microshell /bin/pwd
		./microshell /bin/what_is_this
	---
	2. Implement the semicolon (";"):
		./microshell /bin/ls -la ";" /bin/echo WE ARE MICROSHELLING
	---
	3. Implement the cd built-in command:
		./microshell /bin/mkfir miaou ";" cd miaou
		./microshell cd miaou waf
		./microshell cd
		./microshell cd non-existent
	---
	4. COULD be implementing small pipes, like:
		./microshell /bin/ls "|" /bin/wc -l
		(But I went straight to the whole big cycle of pipes, to the 5.)
	---
	5. Finish the microshell with working pipe system:
		valgrind --track-fds=yes ./microshell /bin/echo HELLO "|" /bin/wc -l ";" /bin/rmdir XXX ";" /bin/mkdir XXX ";" cd XXX ";" /bin/echo ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ";" /bin/cat ../../../subject.en.txt "|" /bin/grep microshell "|" /bin/wc -l ";" /bin/echo ---MIAOU--- ";" /bin/cat ../../../subject.en.txt "|" /bin/grep microshell ";" /bin/echo SUCCESS ";" cd /home/path_to_the_prev_dir ";" /bin/ls

		valgrind --track-fds=yes ./microshell /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls "|" /bin/ls

---
All the stages I've came to can be found in preparations folder as well a another version of microshell that I did again without looking at my preparations.

Good luck!
