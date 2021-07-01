/** 225. Implement Stack using Queues */
/** Implement a last in first out (LIFO) stack using only two queues. 
 *  The implemented stack should support all the functions of a normal queue (push, top, pop, and empty).
 * 
 *  Implement the MyStack class:
 *  void push(int x) Pushes element x to the top of the stack.
 *  int pop() Removes the element on the top of the stack and returns it.
 *  int top() Returns the element on the top of the stack.
 *  boolean empty() Returns true if the stack is empty, false otherwise.
 * 
 *  Notes:
 *  You must use only standard operations of a queue, which means only push to back, 
 *  peek/pop from front, size, and is empty operations are valid.
 *  Depending on your language, the queue may not be supported natively. 
 *  You may simulate a queue using a list or deque (double-ended queue), as long as you use only a queue's standard operations.
 *  
 *  Example 1:
 *  Input
 *  ["MyStack", "push", "push", "top", "pop", "empty"]
 *  [[], [1], [2], [], [], []]
 *  Output
 *  [null, null, null, 2, 2, false]
 * 
 *  Explanation
 *  MyStack myStack = new MyStack();
 *  myStack.push(1);
 *  myStack.push(2);
 *  myStack.top(); // return 2
 *  myStack.pop(); // return 2
 *  myStack.empty(); // return False
 * 
 *  Constraints:
 *  1 <= x <= 9
 *  At most 100 calls will be made to push, pop, top, and empty.
 *  All the calls to pop and top are valid.
 *  Follow-up: Can you implement the stack using only one queue? */


/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.queue = {};
    this.queue.head = null;
    this.queue.size = 0;
    this.queue.push = function (x) {
        if (!this.size) {
            this.head = {val:x, next:null};
        } else {
            let cur = this.head;
            while (cur.next) {
                cur = cur.next;
            }
            cur.next = {val:x, next:null};
        }
        this.size++;
    }

    this.queue.poll = function() {
        if (this.head == null) return null;
        let cur = this.head;
        this.head = this.head.next;
        this.size--;
        return cur.val;
    }

    this.queue.isEmpty = function() {
        return this.size == 0;
    }

};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.queue.push(x);    
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    for (let i = 1; i < this.queue.size; ++i) {
        this.queue.push(this.queue.poll());
    }

    return this.queue.poll();
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
   for (let i = 1; i < this.queue.size; ++i) {
       this.queue.push(this.queue.poll());
   }

   let val = this.queue.poll();
   this.queue.push(val);
   return val;
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.queue.isEmpty();
};

var myStack = new MyStack();
myStack.push(1);
myStack.push(2);
var top = myStack.top(); // return 2
var pop = myStack.pop(); // return 2
var empty = myStack.empty(); // return False
