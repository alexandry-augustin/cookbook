---
title: JavaScript (Node.js)
author: 
date: 
url: 
---

# Require

> "[`require()`](https://nodejs.org/api/modules.html#modules_require) is not part of the standard JavaScript API. But in Node.js, it's a built-in function" -- https://stackoverflow.com/questions/9901082/what-is-this-javascript-require

```javascript
var module_name = require('module_name');
```



# `main()`

> Unlike most other programming languages or runtime environments, Node.js doesn't have a built-in special `main` function to designate the entry point of a program. But there is an easy way to achieve this in Node.js, which we will show in this article.
>
> The pattern is to check if the current module is the main module: `require.main === module`. If this is true, the current file has been run directly - as opposed to have been imported by another file - and in this case we can call the `main` function. Example:
>
> ```javascript
> if(require.main === module)
> {
> 	console.log("Hello world");
> }
> ```
>
> https://mathieularose.com/main-function-in-node-js

# JavaScript

`global` replaces `window`

`process` replaces `document`

# Core Modules

- `fs`: 
- `path`: 
- `http`: 
- `url`:
- `querystring`: 
- `events`: 
- `os`: 
- `util`: 



