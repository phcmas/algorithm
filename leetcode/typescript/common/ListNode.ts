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
}
