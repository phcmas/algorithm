export class ListNode {
  val: number;
  next: ListNode | null;

  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }

  static makeList(numbers: number[]) {
    if (numbers.length === 0) return null;

    const head = new ListNode(numbers[0]);
    let prev = head;

    for (let i = 1; i < numbers.length; ++i) {
      const number = numbers[i];
      const newNode = new ListNode(number);

      prev.next = newNode;
      prev = newNode;
    }

    prev.next = null;
    return head;
  }

  static makeCircularList = (data: [number[], number]) => {
    const numbers = data[0];
    const pos = data[1];
    if (numbers.length === 0) return null;

    const head = new ListNode(numbers[0]);
    let prev = head;
    let cycleStart: ListNode | null = pos === 0 ? head : null;

    for (let i = 1; i < numbers.length; ++i) {
      const newNode = new ListNode(numbers[i]);
      if (i === data[1]) cycleStart = newNode;

      prev.next = newNode;
      prev = newNode;
    }

    prev.next = cycleStart;
    return head;
  };

  static isSameList(head1: ListNode | null, head2: ListNode | null) {
    let node1 = head1;
    let node2 = head2;

    while (node1 !== null) {
      if (node2 === null) return false;
      if (node1.val !== node2.val) return false;

      node1 = node1.next;
      node2 = node2.next;
    }

    return node2 === null;
  }

  // circular list는 각 노드의 값을 -10^5 ~ 10^5 으로 제한시킨다
  static isSameCircularList(head1: ListNode | null, head2: ListNode | null) {
    const maxValue = Math.pow(10, 5);
    const visited = maxValue * 2 + 1;

    let count = 0;
    let node1 = head1;
    let node2 = head2;

    while (node1 !== null && node1.val <= maxValue) {
      if (node2 === null) return false;
      if (node1.val !== node2.val) return false;

      node1.val += visited;
      node2.val += visited;
      node1 = node1.next;
      node2 = node2.next;
      count++;
    }

    if (node1 === null) {
      return node2 === null;
    } else if (node2 === null || node2.val !== node1.val) {
      return false;
    }

    for (let i = 0; i < count; ++i) {
      if (node1.val !== node2.val) return false;
    }

    return true;
  }

  static splitList(node: ListNode | null, start: number, count: number) {
    let head: ListNode | null = node;

    for (let i = 0; i < start; ++i) {
      if (head === null) {
        throw new Error(`cannot split list started from ${start}`);
      }

      head = head.next;
    }

    let end: ListNode | null = head;

    for (let i = 0; i < count - 1; ++i) {
      if (end === null) {
        throw new Error(`cannot split list of node ${count}`);
      }

      end = end.next;
    }

    if (end !== null) end.next = null;
    return head;
  }
}
