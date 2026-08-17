function longestCommonPrefix(strs) {
  const shortestStr = Math.min(...strs.map(s => s.length));
  let out = '';

  for (let i = 0; i < shortestStr; i++) {
    if (new Set(strs.map(s => s[i])).size === 1) out += strs[0][i];
    else break;
  }

  return out;
}

function runLongestCommonPrefix() {
  console.log(longestCommonPrefix(['flower', 'flow', 'flight']));
  console.log(longestCommonPrefix(['dog', 'racecar', 'car']));
}

// --- 2 (removeDuplicates) ---
function removeDuplicates(nums) {
  let len = nums.length;
  for (let i = 1; i < len; i++) {
    if (nums[i] !== nums[i - 1]) continue;

    len--;
    i--;
    for (let j = i; j < len; j++) {
      nums[j] = nums[j + 1];
    }
  }

  return len;
}

function removeDuplicatesSet(nums) {
  let unique = new Set(nums);
  let sorted = [...unique].sort((a, b) => a - b);
  sorted.forEach((v, i) => (nums[i] = v));
  return sorted.length;
}

function removeDuplicatesSecondArr(nums) {
  let unique = [nums[0]];
  for (let i = 1; i < nums.length; i++) {
    if (nums[i] > unique[unique.length - 1]) unique.push(nums[i]);
  }
  for (let i = 0; i < unique.length; i++) {
    nums[i] = unique[i];
  }
  return unique.length;
}

function runRemoveDuplicates() {
  let arr = [1, 1, 2];
  console.log(removeDuplicatesSet(arr));

  arr = [-3, -1, 0, 0, 0, 3, 3];
  console.log(removeDuplicatesSet(arr));
  console.log(arr);
}

// search insert pos
function searchInsert(nums, target) {
  let start = 0;
  let end = nums.length;
  let test = Math.floor((end + start) / 2);

  while (start < end) {
    if (nums[test] == target) return test;

    if (nums[test] < target) start = test + 1;
    if (nums[test] > target) end = test - 1;
    test = Math.floor((end + start) / 2);
  }

  return target > nums[start] ? start + 1 : start;
}

function runSearchInsert() {
  console.log(searchInsert([1, 3, 5, 6], 5));
  console.log(searchInsert([1, 3, 5, 6], 2));
  console.log(searchInsert([1, 3, 5, 6], 7));
  console.log(searchInsert([1, 3, 5, 6], 4));
  console.log(searchInsert([1, 3], 2));
}

// sqrt(x)
function mySqrt(x) {
  if (x === 1) return 1;
  const err = 0.00001;
  let test = x / 2;
  let diff = test * test - x;
  let min = 0;
  let max = x;
  while (Math.abs(diff) > err) {
    if (diff > 0) max = test;
    if (diff < 0) min = test;
    test = (max - min) / 2 + min;
    diff = test * test - x;
  }
  if (Math.abs(Math.round(test) - test) < err) return Math.round(test);
  return Math.floor(test);
}

function runMySqrt() {
  // console.log(mySqrt(4));
  // console.log(mySqrt(8));
  // console.log(mySqrt(9));
  // console.log(mySqrt(12));
  // console.log(mySqrt(16));
  console.log(mySqrt(9801));
  console.log(Math.sqrt(9801));
  console.log(99 * 99);
}

runMySqrt();
