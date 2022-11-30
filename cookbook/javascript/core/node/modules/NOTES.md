---
title: Modules
author: 
date: 
url: 
---

# Exporting Single Function

Module

```javascript
function function_name() {...}
module.exports = function_name;
```

Import

```javascript
const function_name = require('<relative path>/module_name');
function_name();
```

# Exporting Multiple Functions

Module

```javascript
//function definitions
function function_name1() {...}
function function_name2() {...}

module.exports.function_name1 = function_name1;
module.exports.function_name2 = function_name2;
```

Import:

```javascript
const module_name = require('<relative path>/module_name');

//call imported function 
module_name.function_name1();
module_name.function_name2();
```

