#Notes

## Sample Tree Used:
```
			5
		  /   \
	    2       7
	  /   \    /  \
	 1     3  6    8
            \
             4
```

## Create an array of pointers
Every entry has to be initialized with object
```
int size = 5;
Node ** table = new Node*[size];

for(int i = 0; i < size; i++){
	table[i] = new Node;
}


```