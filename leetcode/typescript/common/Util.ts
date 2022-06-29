function isArraySame<T>(arr0: T[], arr1: T[]) {
  if (arr0.length !== arr1.length) return false;

  return arr0.every((element, index) => {
    return element === arr1[index];
  });
}

function isArraySameIgnoringOrder<T>(arr0: T[], arr1: T[]) {
  const sorted0 = arr0.sort();
  const sorted1 = arr1.sort();

  return isArraySame(sorted0, sorted1);
}

function isTwoDimensionalArraySame<T>(twoDimArr0: T[][], twoDimArr1: T[][]) {
  if (twoDimArr0.length !== twoDimArr1.length) return false;

  for (let i = 0; i < twoDimArr0.length; ++i) {
    const arr0 = twoDimArr0[i];
    const arr1 = twoDimArr1[i];

    if (!isArraySame(arr0, arr1)) return false;
  }

  return true;
}

export { isArraySame, isArraySameIgnoringOrder, isTwoDimensionalArraySame };
