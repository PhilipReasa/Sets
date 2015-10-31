#Sets

##About
This is a quick little project that I threw together to explore different potential time complexities for different Set implementations

##Variations
There are three implementations

 1. List based. Just add the element to a list. You can clear the list quickly, but other ops take O(count) time
 2. Map based. Add elements to an array. This works really well if you are using most of your domain. Inset, remove, and lookup are fast, but clear is slow
 3. Hybrid. Use both a List and a Map. Twice the memory footprint, but you can do all ops in O(1)

##Operations
| x        | Insert    | Remove    | Lookup    | Clear  |
|---       |---        |---        |---        |---     |
| LIST     | O(count)  | O(count)  | O(Count)  | O(1)   |
| MAP      | O(1)      | O(1)      | O(1)      | O(N)   |
| HYBRID   | O(1)      | O(1)      | O(1)      | O(1)   |