#Notes

##Sample Tree
```
        20
      /    \
     8      22
   /   \
  4     12
       /  \
     10    14
```

##Steps to find successor
1. If theres a right node
  *Return left most node
2. If no right side, look at parent
  1. If original is on left side, parent is successor
  2. If original is on right side, original is successor