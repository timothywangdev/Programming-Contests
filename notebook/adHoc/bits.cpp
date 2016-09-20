// clear the least significant bit
n&=n-1

// find the position of the least significant bit
pos = n&-n
// then we can use that position to clear it
n-=pos
