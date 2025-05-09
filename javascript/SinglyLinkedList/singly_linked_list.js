class Node {
    next;
    val;

    /**
     * 
     * @param {int} val 
     * @param {Node} next 
     */
    constructor(val, next = null) {
        this.val = val;
        this.next = next;
    }
}

class LinkedList {
    front;
    back;

    constructor() {
        this.front = new Node(-1);
        this.back = this.front;
    }

    /**
     * @param {number} index
     * @return {number}
     */
    get(index) {}

    /**
     * @param {number} val
     * @return {void}
     */
    insertHead(val) {}

    /**
     * @param {number} val
     * @return {void}
     */
    insertTail(val) {}

    /**
     * @param {number} index
     * @return {boolean}
     */
    remove(index) {}

    /**
     * @return {number[]}
     */
    getValues() {}
}
