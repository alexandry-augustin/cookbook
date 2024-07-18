---
title: Tailwindcss dropdown with the use of Alpine.js
author: Larapeak
date: Jun 18, 2020
url: https://larapeak.medium.com/tailwindcss-dropdown-with-the-use-of-alpine-js-85390ed24551
---

We create a button with Tailwindcss. The button has the `relative` class. With this class we can position the `dropdown body` absolute to the button.

Next we will add `x-data="{ open: false }"` attribute. This will initialize a variable `open` that we can use to check if the dropdown is open.

When we press the button, we need to open the `dropdown body`. We do this by adding `x-on:click="open = true"` to the button.

On the `dropdown body` we set a show attribute with an animation if the `open` variable is true. We do this by adding `x-show.transition="open"`. If the user clicks away we want to close the `dropdown body`. We do this with the `x-on:click.away="open = false"` attribute.

That is it! We now have a fully working dropdown modal using Tailwindcss and Alpine.js.