import { smallestCommonElement } from "../2025_08/FindSmallestCommonElementInAllRows";
import { minCost } from "../2025_08/PaintHouse";

describe("2025_08 test", () => {
  it("Find Smallest Common Element in All Rows", () => {
    const mat0 = [
      [1, 2, 3, 4, 5],
      [2, 4, 5, 8, 10],
      [3, 5, 7, 9, 11],
      [1, 3, 5, 7, 9],
    ];
    const mat1 = [
      [1, 2, 3],
      [2, 3, 4],
      [2, 3, 5],
    ];

    const ret0 = smallestCommonElement(mat0);
    const ret1 = smallestCommonElement(mat1);

    expect(ret0).toEqual(5);
    expect(ret1).toEqual(2);
  });

  it("Paint House", () => {
    const costs0 = [
      [17, 2, 17],
      [16, 16, 5],
      [14, 3, 19],
    ];
    const costs1 = [[7, 6, 2]];

    const ret0 = minCost(costs0);
    const ret1 = minCost(costs1);

    expect(ret0).toEqual(10);
    expect(ret1).toEqual(2);
  });
});
