# **UTF-8 Validation**

### **Problem statement**

Write a method that determines if a given data set represents a valid UTF-8 encoding.

* Prototype: `def validUTF8(data)`
* Return: `True` if data is a valid UTF-8 encoding, else return `False`
* A character in UTF-8 can be *1 to 4 bytes long*
* The data set can contain multiple characters
* The data will be represented by a list of integers
* Each integer represents 1 byte of data, therefore you only need to handle the 8 least significant bits of each integer

### **Algorithm**

* Start processing the integers in the given array one by one.
* For every integer, obtain the binary representation in the string format. Since integers can be very large, we should only keep/consider the 8 least significant bits of data and discard the rest as mentioned in the problem statement. After this step, you should have 8-bits or 1-byte string representation for the integer. Let the string we get here be called `bin_rep`.
* There are two scenarios that we need to consider here in the next step.
	* One is that we are in the middle of processing some UTF-8 encoded character. In this case we simply need to check the first two bits of the string and see if they are 10 i.e. the 2 most significant bits of the integer being 1 and 0. bin_rep[:2] == "10"
	* The other case is that we already processed some valid UTF-8 characters and we have to start processing a new UTF-8 character. In that case we have to look at a prefix of the string representation and look at the number of 1s that we encounter before encountering a 0. This will tell us the size of the next UTF-8 character.
* We keep on processing the integers of the array in this way until we either end up processing all of them or we find an invalid scenario.
