To compile program:
```
make
```
	
To run program:
```
make run
```
or
```
./ACS <inputfile>.txt
```
	
To clean:
```
make clean
```

Input file must be in the form:
- Number of expected customers
- A newline (\n)
- (Repeat per customer)
- Unique customer ID
- A colon (:)
- Customer queue selection (0 or 1)
- A comma (,)
- Customer arrival time
- A comma (,)
- Customer service time
- A newline (\n)


Example input file:
```
7
1:0,2,60
2:0,4,70
3:0,5,50
4:1,7,30
5:1,7,40
6:1,8,50
7:0,10,30
```
