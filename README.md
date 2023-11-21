# fract_ol

fract_ol is my first graphic project for 42Paris' common core. The goal is to draw a fractal on a window, using the minilibx graphic library.

What is a fractal ? Well, first of all we're going to need just a little bit of maths. Don't worry, I'm going to make it crystal clear.
Let's consider this function : f(z) = z². Let's take a number, any number. For example : 2. Let's pass it through our function.

f(2) = 2² = 4

Well done, we've just had our first iteration of our function for the number 2. Now let's take the number we got from passing 2 into our function (so, 4), and pass it in our function again.

f(4) = 4² = 16

Good, second iteration. Now let's do it again.

f(16) = 16² = ...???

I have no idea what 16² is. I could use a calculator and tell you, but that's not the point. The point is : the more we iterate, the larger the number gets. For this function, it takes just a few iterations to understand that we're never going back. We are leaning towards... INFINITY !

Great work, but... What does any of this has to do with psychedelic videos zooming in infinitely or ferns ?

Well, let's imagine a straight line. This line represents every real number, with 0 at the center (I know, lines don't have centers, bear with me), negative numbers at the left and positive at the right. So on this line, we have every number that we can put in our function to discover what it does.

Don't they all lean towards infinity ? Nope ! Try our function with 1 and you'll quickly realize that we have two possibilities : either it leans towards infinity, or it just stays within the boundaries of 0 and 1.

Let's put some colour on our line. Black for numbers that stay stable when we iterate our function with them, and white if they lean towards infinity. What we get is quite boring unfortunately : a simple white line with black between -1 and 1.

This is our first graphic representation of the basic concepts that will get us to fractals. Let's make it a little more complex so we get something prettier.

Instead of taking as our function f(z) = z², we're going to use the one Benoit Mandelbrot used to show everyone how awesome fractals were : f(z) = z² + c.

Now we have two variables, z and c. We're going to establish, quite arbitrarily, that z will always be 0 for our first iteration, and c will be the number on our line. Let's try with c = 1.

f(0) = 0² + 1 = 1.
f(1) = 1² + 1 = 2.
f(2) = 2² + 1 = 5.
f(5) = 5² + 1 = 26.
f(26) = 26² + 1 = ...?

You get the rest. Where before, with 1, our iterations stayed stable, here, they lean towards infinity. Let's color our line white for 1.
Same for -1 right ? Nope. Here it is for -1.

f(0) = 0² - 1 = -1.
f(-1) = (-1)² - 1 = 0.
f(0) = 0² - 1 = -1.
f(-1) = (-1)² - 1 = 0.

Stable. It's not leaning towards anything, it's just going back and forth between two values. Paint it black.

The idea is : the behaviour is completely different. If you look at the picture of a mandelbrot set with coordinates (you can look it up) and look at the abscissa (horizontal line), you'll see in color the numbers of c for which the iterations go crazy, and in black those for which it stays put.

