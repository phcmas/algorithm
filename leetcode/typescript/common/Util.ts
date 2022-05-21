export const isArraySame = (arr0: number[], arr1: number[]) => {
  if (arr0.length !== arr1.length) return false;

  return arr0.every((element, index) => {
    return element === arr1[index];
  });
};
