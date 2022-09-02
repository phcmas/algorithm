import { closedIsland } from "../2022_09/NumberOfClosedIslands";

describe("2022_08 test", () => {
  it("push dominoes", () => {
    const grid0 = [
      [1, 1, 1, 1, 1, 1, 1, 0],
      [1, 0, 0, 0, 0, 1, 1, 0],
      [1, 0, 1, 0, 1, 1, 1, 0],
      [1, 0, 0, 0, 0, 1, 0, 1],
      [1, 1, 1, 1, 1, 1, 1, 0],
    ];

    const grid1 = [
      [0, 0, 1, 0, 0],
      [0, 1, 0, 1, 0],
      [0, 1, 1, 1, 0],
    ];

    const grid2 = [
      [1, 1, 1, 1, 1, 1, 1],
      [1, 0, 0, 0, 0, 0, 1],
      [1, 0, 1, 1, 1, 0, 1],
      [1, 0, 1, 0, 1, 0, 1],
      [1, 0, 1, 1, 1, 0, 1],
      [1, 0, 0, 0, 0, 0, 1],
      [1, 1, 1, 1, 1, 1, 1],
    ];

    const grid3 = [
      [0, 0, 1, 1, 0, 1, 0, 0, 1, 0],
      [1, 1, 0, 1, 1, 0, 1, 1, 1, 0],
      [1, 0, 1, 1, 1, 0, 0, 1, 1, 0],
      [0, 1, 1, 0, 0, 0, 0, 1, 0, 1],
      [0, 0, 0, 0, 0, 0, 1, 1, 1, 0],
      [0, 1, 0, 1, 0, 1, 0, 1, 1, 1],
      [1, 0, 1, 0, 1, 1, 0, 0, 0, 1],
      [1, 1, 1, 1, 1, 1, 0, 0, 0, 0],
      [1, 1, 1, 0, 0, 1, 0, 1, 0, 1],
      [1, 1, 1, 0, 1, 1, 0, 1, 1, 0],
    ];

    const ans0 = 2;
    const ans1 = 1;
    const ans2 = 2;
    const ans3 = 5;

    const ret0 = closedIsland(grid0);
    const ret1 = closedIsland(grid1);
    const ret2 = closedIsland(grid2);
    const ret3 = closedIsland(grid3);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
    expect(ret3).toEqual(ans3);
  });
});
