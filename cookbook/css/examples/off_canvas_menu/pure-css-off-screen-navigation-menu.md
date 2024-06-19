---
title: Pure CSS Off-screen Navigation Menu
author: Austin Wulf
date: July 31, 2014
url: https://www.sitepoint.com/pure-css-off-screen-navigation-menu/
---

Hamburger menu, drawer menu, off-canvas menu: Whatever you call it,  hiding a website’s primary navigation just off screen is becoming a  ubiquitous pattern in responsive web design. More and more sites feature a fixed-position icon that, when tapped, pushes the entire site to the  side to reveal a hidden navigation menu.

While there are plenty of jQuery plugins that will create this effect for you, it’s actually pretty easy to achieve without using any  JavaScript at all.

This article will show you how to make a simple version of the off-canvas menu and sliding effect using only CSS.

Before we get started, I’d like to make a note that using this method for creating the drawer menu means your site’s navigation will always  be in a drawer, regardless of viewport size. If you only want the drawer menu on smaller screens, you’ll have to use some JavaScript to  manipulate the DOM order or use some funky CSS to make the menu look  right on larger screens. In other words: It’s pretty and simple, but  it’s not always the right solution for every situation.

Here’s a CodePen demo showing the end result:

## Start with Some HTML

The markup for our off-canvas menu is a bit different than your  standard navigation menu. Instead of sticking it in the site’s header,  we’re going to start right inside the `<body>` tag.

This is the basic structure:

```
<ul class="navigation">
    <li class="nav-item"><a href="#">Home</a></li>
    <li class="nav-item"><a href="#">Portfolio</a></li>
    <li class="nav-item"><a href="#">About</a></li>
    <li class="nav-item"><a href="#">Blog</a></li>
    <li class="nav-item"><a href="#">Contact</a></li>
</ul>

<input type="checkbox" id="nav-trigger" class="nav-trigger" />
<label for="nav-trigger"></label>

<div class="site-wrap">
    <!-- insert the rest of your page markup here -->
</div>
```

You can see our site’s markup is made up of three main elements: the  navigation, a checkbox and label pair, and the site’s actual content.

A few things to note:

- The navigation section is first in the source order because it’s  “behind” everything else on the site. You can use whatever HTML tags you want to build the navigation. Here I’m using an unordered list, which  is common.
- The trigger to slide out our menu is a checkbox input with a label.  Typically the label would come before the input or wrap around the  input. In this case, the input has to come directly before the label.  We’ll see why later when we add the CSS.
- The rest of our site has to be wrapped in a unique div. This is so  that when we open the menu, everything else can slide slightly  off-screen to reveal the hidden navigation elements underneath.

Now that we’ve got our basic HTML structure, we can start making it look pretty!

Let’s start by styling the navigation menu and items. First off, we  need to make sure our navigation menu is behind our page content and  that it stays in place even if a user scrolls:

```
.navigation {
    list-style: none;
    background: #111;
    width: 100%;
    height: 100%;
    position: fixed;
    top: 0;
    right: 0;
    bottom: 0;
    left: 0;
    z-index: 0;
}
```

Next, I’ve added some styles to make our navigation look snazzy  (background colors, borders, gradients, etc.). I won’t reproduce the  code here, but you can review the demo to check those out.

Now we have some nice looking menu items, but it doesn’t look so  great with all of our content just laying on top of it. Let’s add some  styling to hide the menu until we’re ready for it.

## The CSS for the Site Wrapper

To start, let’s make sure the site’s content completely covers our  menu. At this point, you may want to add a few paragraphs of lorem ipsum to your `.site-wrap` element, if you haven’t already added any content.

```
.site-wrap {
    min-width: 100%;
    min-height: 100%;
    background-color: #fff;
    position: relative;
    top: 0;
    bottom: 100%;
    left: 0;
    z-index: 1;
}
```

Note that we must specify a background on `.site-wrap` or else the menu will show through. You can, of course, use any kind of background you want. I added the following to mine:

```
.site-wrap {
    /* ...previous styles here... */
    padding: 4em;
    background-image: linear-gradient(135deg, 
                      rgb(254,255,255) 0%,
                      rgb(221,241,249) 35%,
                      rgb(160,216,239) 100%);
    background-size: 200%;
}
```

Next we’ll add the styles that change the menu trigger from a  standard checkbox input into the classic “hamburger” icon that we all  know and love.

First, let’s hide the checkbox.

```
.nav-trigger {
    position: absolute;
    clip: rect(0, 0, 0, 0);
}
```

*Editor’s note: Originally, this code was using `display: block` along with zero width and height for the checkbox, to make it invisible but still accessible. It turns out, this combination was causing iOS to crash the browser when the menu was opened. I’ve changed the technique  to use the `clip` property instead, which seems to have the same level of accessibility.*

Here we are hiding the checkbox using the clip property, which requires that the element be set to `position: absolute`.

Now let’s style the `<label>` element:

```
label[for="nav-trigger"] {
    position: fixed;
    top: 15px;
    left: 15px;
    z-index: 2;
}
```

First, we set the label to `position: fixed` so that it stays in the same spot as the user scrolls. The `top` and `left` properties dictate how far from the edge of the viewport the icon will sit. We also make sure the trigger’s `z-index` is at least one higher than that of the `.site-wrap` element.

Next, we add additional declaratins to make the lable into a “hamburger” icon.

```
label[for="nav-trigger"] {
    /* ... previous styles here... */
    width: 30px;
    height: 30px;
    cursor: pointer;
    background-image: url("data:image/svg+xml;utf8,<svg xmlns='https://www.w3.org/2000/svg' xmlns:xlink='https://www.w3.org/1999/xlink' version='1.1' x='0px' y='0px' width='30px' height='30px' viewBox='0 0 30 30' enable-background='new 0 0 30 30' xml:space='preserve'><rect width='30' height='6'/><rect y='24' width='30' height='6'/><rect y='12' width='30' height='6'/></svg>");
    background-size: contain;
}
```

I’ve used [inline SVG](https://stackoverflow.com/questions/10768451/inline-svg-in-css) as a background image, but you can use [any icon you want](https://css-tricks.com/three-line-menu-navicon/), including `:before` and `:after` pseudo elements to recreate the “hamburger” icon using pure CSS.

Notice I’ve also included `cursor: pointer;` to visually indicate interactivity with cursor-based input.

## The CSS to Make the Trigger Work

Now that our menu, site wrapper, and trigger are all styled, let’s add the last few lines of CSS that make it all work.

```
.nav-trigger:checked + label {
    left: 215px;
}

.nav-trigger:checked ~ .site-wrap {
    left: 200px;
    box-shadow: 0 0 5px 5px rgba(0,0,0,0.5);
}
```

The second declaration block above ensures that the site wrapper is  pushed to the right by 200 pixels. I also added a box shadow to the site wrapper to give it that extra visual feel of being stacked on top of  the menu.

The first selector (`.nav-trigger:checked + label`) controls the position of the trigger when the menu is open. You’ll want to add the number we used earlier on `label[for="nav-trigger"]` to the amount you want the site wrapper to slide out. So in this case: 15px + 200px = 215px.

This is where the source order of the trigger elements becomes important. The second selector uses `~`, the general sibling selector, to target `.site-wrap` when `.nav-trigger` is checked. The source order of our checkbox input isn’t as important here.

However, we have to target both `.site-wrap` and our `<label>` element based on whether or not our checkbox input is checked. To accomplish this, we use the `+` (adjacent sibling selector) to target the `<label>` element that’s next to the checked checkbox. If we put the label first, there’s no way to move it along with the site wrapper when we activate  our trigger.

As a finishing touch, we can add a CSS transition to both the trigger and the site wrapper to open the menu with a smooth animation. Make  sure to include any relevant browser-prefixed attributes in your  version, or else use something like [Autoprefixer](https://github.com/postcss/autoprefixer).

```
.nav-trigger + label, .site-wrap {
    transition: left 0.2s;
}
```

One last thing: Make sure to hide any overflow on the x-axis of your `<body>`. Without this, your users will be able to scroll the whole window left and right when the menu is open.

```
body {
    overflow-x: hidden;
}
```

## The Finished Product

And that’s it! We’ve successfully built a slick off-screen navigation menu without any JavaScript. Again, here’s the CodePen to demonstrate  what it looks like when it all comes together:

Now that you know how it’s done, feel free to play around with the  idea. Make a version that slides in from the right, or make one that has both a left and right menu.

I’d love to see what you can come up with, so share a CodePen of your own design in the comments, or links to other examples of pure CSS  off-screen navigation menus.

### How can I create a pure CSS off-screen navigation menu?

Creating a pure CSS off-screen navigation menu involves several steps. First,  you need to define the HTML structure of your menu. This typically  includes a wrapper div, a button to toggle the menu, and an unordered  list for the menu items. Next, you need to style your menu using CSS.  This involves setting the position of the menu off-screen and using the  :checked pseudo-class to move it on-screen when the toggle button is  clicked. You can also add transitions to make the movement smoother.  Finally, you need to add the functionality to close the menu when a menu item is clicked. This can be achieved using the :target pseudo-class.

### Can I use JavaScript to create an off-screen navigation menu?

Yes, you can use JavaScript to create an off-screen navigation menu.  However, the advantage of using pure CSS is that it’s lighter and  faster, as it doesn’t require the browser to interpret JavaScript code.  Moreover, a pure CSS solution will work even if the user has disabled  JavaScript in their browser.

### How can I make my off-screen navigation menu responsive?

To make your off-screen navigation menu responsive, you can use media  queries in your CSS. Media queries allow you to apply different styles  depending on the size of the user’s screen. For example, you can set the width of the menu to 100% on small screens and to a fixed size on  larger screens.

### Can I add animations to my off-screen navigation menu?

Yes, you can add animations to your off-screen navigation menu using CSS  transitions. Transitions allow you to control the speed and timing of  the movement of the menu. You can also use CSS keyframes to create more  complex animations.

### How can I style the toggle button of my off-screen navigation menu?

You can style the toggle button of your off-screen navigation menu using  CSS. You can change its color, size, and position, and you can add a  hover effect. You can also use the :before and :after pseudo-elements to create a hamburger icon.

### How can I add submenus to my off-screen navigation menu?

To add submenus to your off-screen navigation menu, you can nest unordered lists within your menu items. You can then use CSS to hide the submenus by default and show them when the parent menu item is hovered over or  clicked.

### Can I use a pure CSS off-screen navigation menu in a WordPress theme?

Yes, you can use a pure CSS off-screen navigation menu in a WordPress theme. You can add the HTML structure of the menu to your theme’s header.php  file and the CSS to your style.css file. You can then use the WordPress  menu functions to populate the menu with your site’s pages.

### How can I add a backdrop to my off-screen navigation menu?

To add a backdrop to your off-screen navigation menu, you can create a  full-screen div and position it behind the menu. You can then use the  :checked pseudo-class to show the backdrop when the menu is open.

### How can I make my off-screen navigation menu accessible?

To make your off-screen navigation menu accessible, you can use ARIA roles and attributes in your HTML. For example, you can use the  role=”navigation” attribute on your menu and the aria-expanded attribute on your toggle button. You can also add keyboard navigation using the  :focus pseudo-class in your CSS.

### Can I use a pure CSS off-screen navigation menu in an email?

While it’s technically possible to use a pure CSS off-screen navigation menu  in an email, it’s not recommended. Many email clients have limited  support for CSS, especially for advanced features like transitions and  animations. Moreover, the user experience of a navigation menu in an  email can be confusing, as users typically expect emails to be static.