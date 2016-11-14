## QuantLib Async Bindings for Node.js [![npm version](https://badge.fury.io/js/quantlib.svg)](http://badge.fury.io/js/quantlib)

This project brings [QuantLib](http://quantlib.org/) to the Node.js community, it's similar to [QuantLibXL](http://quantlib.org/quantlibxl/) project which is for Microsoft Excel.

Most functions in QuantLibXL can be used in the similar way in Node on the server side.

All functions in this project are Async, they are exported to [Promise](https://www.promisejs.org/) sytle function, please see [Example](#example) below.


## Getting started

```sh
npm install quantlib
```

* Windows

`npm install quantlib` will do everything, including the node package installation and pre-built native addon (no dependency) download, you can start use it right away.

* Linux & Mac

Quantlib and QuantLibAddin must be built first, then build QuantLibNode linking to them, pre-built native code is not provided for now


## QuantLib Documents

* [Function Categories](http://quantlib.org/quantlibxl/categories.html)

* [Function List](http://quantlib.org/quantlibxl/allfunctions.html)

## Version Matrix

| QuantLib | QuantLibAddin | Node.js | quantlib.node |
| -------- | ------------- | ------- | ------------- |
|    1.7.1 |         1.7.0 |   6.9.1 |         0.1.x |

## Example

```js
var ql = require('quantlib');

var mtx1 =
[
  [1.00000,	0.97560,	0.95240,	0.93040,	0.90940,	0.88940,	0.87040,	0.85230,	0.83520,	0.81880],
  [0.97560,	1.00000,    0.97560,    0.95240,    0.93040,    0.90940,    0.88940,    0.87040,    0.85230,    0.83520],
  [0.95240,	0.97560,	1.00000,	0.97560,	0.95240,	0.93040,	0.90940,	0.88940,	0.87040,	0.85230],
  [0.93040,	0.95240,	0.97560,	1.00000,	0.97560,	0.95240,	0.93040,	0.90940,	0.88940,	0.87040],
  [0.90940,	0.93040,	0.95240,	0.97560,	1.00000,	0.97560,	0.95240,	0.93040,	0.90940,	0.88940],
  [0.88940,	0.90940,	0.93040,	0.95240,	0.97560,	1.00000,	0.97560,	0.95240,	0.93040,	0.90940],
  [0.87040,	0.88940,	0.90940,	0.93040,	0.95240,	0.97560,	1.00000,	0.97560,	0.95240,	0.93040],
  [0.85230,	0.87040,	0.88940,	0.90940,	0.93040,	0.95240,	0.97560,	1.00000,	0.97560,	0.95240],
  [0.83520,	0.85230,	0.87040,	0.88940,	0.90940,	0.93040,	0.95240,	0.97560,	1.00000,	0.97560],
  [0.81880,	0.83520,	0.85230,	0.87040,	0.88940,	0.90940,	0.93040,	0.95240,	0.97560,	1.00000]
];

ql.SymmetricSchurDecomposition('mtx#1',mtx1).then(function(obj){

  ql.SymmetricSchurDecompositionEigenvalues(obj).then(function(r){
    console.log(r);
  });

}).catch(function(e){
  console.log(e);
});

```

```sh
>
[ 9.270906840163782,
  0.4207173234885105,
  0.12674770658244172,
  0.059239731356788505,
  0.03595303870722261,
  0.024956978505270924,
  0.019117669503864024,
  0.01580103250921176,
  0.01377474504269164,
  0.012784934140218302 ]
```
