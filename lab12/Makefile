part1:
	g++ pair.cpp part1.cpp -o part1
	
part2: 
	g++ pair.cpp part2.cpp -o part2	
part3: 
	g++ pair.cpp part3.cpp -o part3	
part4: 
	g++ pair.cpp part4.cpp -o part4	

############# DON'T TOUCH BELOW ################
run%: part%
	@valgrind ./part$* 2> out; python3 val.py
