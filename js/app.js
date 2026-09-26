function merge(nums1, m, nums2, n) {
  m--;
  n--;
  while (m >= 0 || n >= 0) {
    let out_index = m + n + 1;
    if (m === -1) {
      nums1[out_index] = nums2[n];
      n--;
      continue;
    }
    if (n === -1) {
      nums1[out_index] = nums1[m];
      m--;
      continue;
    }

    if (nums1[m] > nums2[n]) {
      nums1[out_index] = nums1[m];
      m--;
    } else {
      nums1[out_index] = nums2[n];
      n--;
    }
  }
}

let val1 = [1, 2, 3, 0, 0, 0];
let val2 = [2, 5, 6];
merge(val1, 3, val2, 3);
console.log(val1);
