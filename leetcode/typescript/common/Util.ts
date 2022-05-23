export const isArraySame = (arr0: number[], arr1: number[]) => {
  if (arr0.length !== arr1.length) return false;

  return arr0.every((element, index) => {
    return element === arr1[index];
  });
};

export const isArraySameIgnoringOrder = (arr0: number[], arr1: number[]) => {
  const sorted0 = arr0.sort();
  const sorted1 = arr1.sort();

  return isArraySame(sorted0, sorted1);
};
