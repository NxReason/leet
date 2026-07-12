import assert from './assert.js';

function rgb(r, g, b) {
  return [r, g, b]
    .map(c => {
      if (c < 0) return 0;
      if (c > 255) return 255;
      return c;
    })
    .map(num => num.toString(16).toUpperCase())
    .map(hex => (hex.length < 2 ? `0${hex}` : hex))
    .join('');
}

assert(rgb(255, 255, 255), 'FFFFFF');
assert(rgb(255, 255, 300), 'FFFFFF');
assert(rgb(0, 0, 0), '000000');
assert(rgb(148, 0, 211), '9400D3');
