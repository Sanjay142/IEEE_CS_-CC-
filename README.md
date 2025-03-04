

1. Custom Stack
This program implements a stack with additional features that allow you to:
push(x): Add a new element to the stack.
pop(): Remove the top element from the stack.
top(): Retrieve the top element without removing it.
getMin(): Get the smallest element in the stack.
getMax(): Get the largest element in the stack.

How it works:
The main stack holds all elements.
Two additional stacks track the minimum and maximum values.
When a new element is added, the program updates the min and max stacks.
This allows retrieving the minimum and maximum in constant time.

Efficiency:
Time Complexity: O(1) for all operations.
Space Complexity: O(n) for the stack size.

Example:
1. push(5) → stack: [5], min: [5], max: [5]
2. push(2) → stack: [5, 2], min: [5, 2], max: [5, 5]
3. getMin() → 2
4. getMax() → 5
5. pop() → stack: [5], min: [5], max: [5]

---

2. Interval Merger
This program manages a list of non-overlapping intervals and merges them when necessary.

Operations:
addInterval(start, end): Adds a new interval to the list. If the new interval overlaps with existing ones, they are merged.
getIntervals(): Returns the current list of non-overlapping intervals in sorted order.

How it works:
The program keeps the intervals sorted.
When a new interval is added, it checks for overlaps with the existing intervals.
If there is an overlap, the intervals are merged into a single continuous interval.

Efficiency:
Time Complexity: O(log n) for insertion and merging using binary search.
Space Complexity: O(n) for storing the intervals.

Example:
1. addInterval(1, 5) → [[1, 5]]
2. addInterval(6, 8) → [[1, 5], [6, 8]]
3. addInterval(4, 7) → [[1, 8]]

---
3. Time-Based Cache
This program implements a cache that stores key-value pairs with an expiration time. Expired items are removed automatically.

Operations:
set(key, value, expiryTime): Stores a key-value pair with a specific expiration time. If the key already exists, the value and expiry time are updated.
get(key): Retrieves the value if the key exists and has not expired. If the key does not exist or has expired, it returns None.

How it works:
- A hash map is used to store key-value pairs along with their expiry times.
- A priority queue (min-heap) keeps track of expiration times in ascending order.
- Whenever a value is retrieved or a new key is added, the cache removes any expired entries.

Efficiency:
- Time Complexity: O(log n) for both set and get operations.
- Space Complexity: O(n) for storing active keys.

Example:
1. set("a", 5, 60) → Stores the value 5 with a 60-second expiry.
2. get("a") → 5 if not expired, otherwise None.
3. If 60 seconds pass, "a" is automatically removed.
