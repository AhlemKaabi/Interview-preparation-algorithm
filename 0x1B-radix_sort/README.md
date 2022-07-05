# **Radix Sort Algorithm**

> The Radix sort is a non-comparative sorting algorithm. The Radix sort algorithm is the most preferred algorithm for the unsorted list.
> It sorts the elements by initially grouping the individual digits of the same place value. The idea of Radix Sort is to do digit by digit sort starting from least significant digit(LSD) to the most significant digit(MSD), according to their increasing/decreasing order.

## **Problem statement**
Write a function that sorts an array of integers in ascending order using the `Radix sort` algorithm.

* Prototype: `void radix_sort(int *array, size_t size);`
* You must implement the `LSD`(Least significant digit) radix sort algorithm
* You can assume that `array` will contain only numbers `>= 0`
* You are allowed to use malloc and free for this task
* You’re expected to print the `array` each time you increase your `significant digit` (See example below)

## **Example**

```
0x1B-radix_sort$ ./radix
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## **Algorithm**
```
RadixSort(a[], n):
    // Finding the maximum element
    max=a[0]
    For (i=1 to n-1):
        If (a[i]>max):
            max=a[i]

    // Calling countingSort for
    // k times using For loop.
    For (div=1 to max/div>0):
        countingSort(a, n, div)
        div=div*10
```
## **Running Time**
Radix sort operates in `O(nw)` time, where `n` is the number of `keys`, and `w` is `the key length`.
They are constrained to `lexicographic data`, but for many practical applications this is not a limitation

## **Helpful Resources**

* [Counting Sort Algorithm](https://www.youtube.com/watch?v=OKd534EWcdk)
* [Radix Sort Algorithm Introduction](https://www.youtube.com/watch?v=XiuSW_mEn7g)
* [Radix Sort](https://www.geeksforgeeks.org/radix-sort/)
* [Radix Sort Algorithm in Data Structure](https://www.scaler.com/topics/data-structures/radix-sort/)
* [Radix sort - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort#Complexity_and_performance)