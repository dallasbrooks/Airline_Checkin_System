To compile program:
	`make`
To run program:
	`make run`
	or
	`./ACS <inputfile>.txt`

Input file must be in the form:<br>
	1. First character specifies the unique ID of customers<br>
	2. A colon(:) immediately follows the unique number of the customer<br>
	3. Immediately following is an integer equal to either 1 (indicating the customer belongs to business class) or 0 (indicating the customer belongs to economy class)<br>
	4. A comma(,) immediately follows the previous number<br>
	5. Immediately following is an integer that indicates the arrival time of the customer<br>
	6. A comma(,) immediately follows the previous number<br>
	7. Immediately following is an integer that indicate the service time of the customer<br>
	8. a newline(\n) ends a line<br>

`
	Example input file:
		7
		1:0,2,60
		2:0,4,70
		3:0,5,50
		4:1,7,30
		5:1,7,40
		6:1,8,50
		7:0,10,30
`