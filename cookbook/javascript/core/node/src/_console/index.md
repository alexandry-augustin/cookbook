---
title: How to save logs to files instead of showing it to the console in Node.js?
author: MELVIN GEORGE
date: November 2, 2020 
url: https://melvingeorge.me/blog/save-logs-to-files-nodejs
---

Most of the time when we develop applications we use the `console.log()` method to log information directly to the console regarding the process in Node.js.

We usually do those loggings like this,

```
// log something to console
console.log("Hello 😃 ");
```

But this may not be enough in some cases as we may also want to save some of those logs for safekeeping and reporting.

In that case, we can create a custom logger that saves logs to files.

For that first we need to get the `Console` class from the `console` module like this,

```
// get the Console class
const { Console } = require("console");
```

Now we need to make a new Console logger and pass the `stdout` and `stderr` as an object to the new `Console` class like this,

```
// get the Console class
const { Console } = require("console");

// make a new logger
const myLogger = new Console({
  stdout: "", // a write stream,
  stderr: "", // a write stream
});
```

We have made the new logger called `myLogger` but we haven't passed the values to `stdout` and `stderr`.

The `stdout` refers to the normal log output and the `stderr` refers to the error outputs.

Both the `stdout` and `stderr` accepts a write stream. If you want to know more about Write streams check out [How to create a write stream in Node.js?](https://melvingeorge.me/blog/create-write-stream-node).

Let's make a write stream called `normalStdout.txt` where we want all of the normal logs to be saved and another write stream called `errStdErr.txt` where we want all of the error logs to be saved.

```
// get the Console class
const { Console } = require("console");
// get fs module for creating write streams
const fs = require("fs");

// make a new logger
const myLogger = new Console({
  stdout: fs.createWriteStream("normalStdout.txt"),
  stderr: fs.createWriteStream("errStdErr.txt"),
});
```

We made our custom logger! Yay 🚀!

Now let's test out `myLogger` by using the same method we were using with the normal `console` object like `log()` and `error()` methods.

```
// get the Console class
const { Console } = require("console");
// get fs module for creating write streams
const fs = require("fs");

// make a new logger
const myLogger = new Console({
  stdout: fs.createWriteStream("normalStdout.txt"),
  stderr: fs.createWriteStream("errStdErr.txt"),
});

// saving to normalStdout.txt file
myLogger.log("Hello 😃. This will be saved in normalStdout.txt file");

// saving to errStdErr.txt file
myLogger.error("Its an error ❌. This will be saved in errStdErr.txt file");
```

Now the normal logs will be saved to the `normalStdout.txt` file and the error logs will be saved to the `errStdErr.txt` file.

See this example live in [repl.it](https://repl.it/@melvin2016/save-logs-to-file-instead-of-console#index.js).

### Feel free to share if you found this useful 😃.