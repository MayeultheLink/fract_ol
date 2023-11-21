# fract_ol

fract_ol is my first graphic project for 42Paris' common core. The goal is to draw a fractal on a window, using the minilibx graphic library.

What is a fractal? Well, first of all we're going to need just a little bit of maths. Don't worry, I'm going to make it crystal clear.
Let's consider this function : f(z) = z². Let's take a number, any number. For example : 2. Let's pass it through our function.

f(2) = 2² = 4

Well done, we've just had our first iteration of our function for the number 2. Now let's take the number we got from passing 2 into our function (so, 4), and pass it in our function again.

f(4) = 4² = 16

Good, second iteration. Now let's do it again.

f(16) = 16² = ...???

I have no idea what 16² is. I could use a calculator and tell you, but that's not the point. The point is : the more we iterate, the larger the number gets. For this function, it takes just a few iterations to understand that we're never going back. We are leaning towards... INFINITY!

Great work, but... What does any of this has to do with psychedelic videos zooming in infinitely or ferns?

Well, let's imagine a straight line. This line represents every real number, with 0 at the center (I know, lines don't have centers, bear with me), negative numbers at the left and positive at the right. So on this line, we have every number that we can put in our function to discover what it does.

Don't they all lean towards infinity? Nope! Try our function with 1 and you'll quickly realize that we have two possibilities : either it leans towards infinity, or it just stays within the boundaries of 0 and 1.

Let's put some colour on our line. Black for numbers that stay stable when we iterate our function with them, and white if they lean towards infinity. What we get is quite boring unfortunately : a simple white line with black between -1 and 1.

This is our first graphic representation of the basic concepts that will get us to fractals. Let's make it a little more complex so we get something prettier.

Instead of taking as our function f(z) = z², we're going to use the one Benoit Mandelbrot used to show everyone how awesome fractals were : f(z) = z² + c.

Now we have two variables, z and c. We're going to establish, quite arbitrarily, that z will always be 0 for our first iteration, and c will be the number on our line. Let's try with c = 1.

f(0) = 0² + 1 = 1

f(1) = 1² + 1 = 2

f(2) = 2² + 1 = 5

f(5) = 5² + 1 = 26

f(26) = 26² + 1 = ...?

You get the rest. Where before, with 1, our iterations stayed stable, here, they lean towards infinity. Let's color our line white for 1.
Same for -1 right? Nope. Here it is for -1.

f(0) = 0² - 1 = -1

f(-1) = (-1)² - 1 = 0

f(0) = 0² - 1 = -1

f(-1) = (-1)² - 1 = 0

Stable. It's not leaning towards anything, it's just going back and forth between two values. Paint it black.

The idea is : the behaviour is completely different. If you look at the picture of a Mandelbrot set with coordinates (you can look it up) and look at the abscissa axis (horizontal line), you'll see in color the numbers of c for which the iterations go crazy, and in black those for which it stays put.

I bet you're wondering about two things :
1) A line is fine and all, but how do we get a two dimension image with this technique? I can't draw a Mandelbrot set shape on a line!
2) The Mandelbrot set that I found is not just black and white, what about the shades of colour that will get us the psychedelic effect?

Once we have answered both those questions, we will be ready to draw.

First, we need to add a dimension to our function, so we can draw not just on a line, but on a plane. How do we do that? Well, we can use what mathematicians call complex numbers. A complex number is this : a + ib, where a and b are two numbers, and i is a number where i² = -1. i is called an imaginary unit. That's because no matter the number you can think of that is on our line, if you multiply it by itself, it will give you a positive number. Not i. i times i will give you -1, which means that this number, i, does not exists on our line. One could say it exists on a different dimension.

Let's go back to our function f(z) = z² + c. We are going to stick with it, but c, instead of a regular number, will be complex number, where in a + ib, a is the abscissa, and b the ordinate. We can rewrite our function like this : f(z) = z² + a + ib

And now we can have a two dimension image! When looking at your Mandelbrot set with coordinates, you can see that. For example, for a = 1 and b = 0.5, it is coloured, whereas for a = -0.5 and b = 0.1, it's black.

Let's try with an example and see what it does. Let's try with a = 1 and b = 1.

f(0) = 0² + 1 + i1 = 1 + i

f(1 + i1) = (1 + i)² + 1 + i1 = 1 + 2i + -1 + 1 + i = 1 + 3i

f(1 + 3i) = (1 + 3i)² + 1 + i1 = 1 + 6i + -9 + 1 + i = -7 + 7i

f(-7 + 7i) = (-7 + 7i)² + 1 + i1 = 49 + -98i + -49 + 1 + i = 1 - 97i

It's not that easy to say if it is staying stable or if it is going to blow up. That's where our shades of colour come useful.

Let's take the iterations with a = 1 and b = 0. Turns out we already did this one, it's the one that goes 1, 2, 5, 26, ...?. For this one, it quickly appears that it's leaning towards infinity. Therefore, we paint this point with a bright colour. In fact, let's make this a rule : the quicker it appears to lean towards infinity, the brighter the color.

And there we have it. A mesmerizing shape in which we can zoom in for eternity without ever reaching an end. 

The infinitely zooming in effect is because you can always get more precise with more iterations to see where it's going, but you can never get to the last iteration. Iterations are like peanuts : you can always have one more.

You can see this concept of number of iterations visually in this program by choosing the Serpienski's Carpet mode. When you launch it, you will get a blue square in a white square. If the white square has a side of 1, then the blue square has a side of 1/3, dividing the white square into nine new squares, themselves to be divided into 9 square by a blue square, and so on and so on. Try it by pressing 'T'. The more you iterate by pressing 'T', the more your fractal is precise.

The same goes for our Mandelbrot set. Some people have showed that, if on one of the iteration, the result is strictly above 2, then it means it is leaning towards infinity. Therefore, for each coordinate, we iterate until we go beyond 2, or until we've considered we tried enough times so we can say it's not leaning towards infinity.

In this program, the default number of iterations we try is 50. But you can go further by pressing 'T', and you'll see that everytime you press 'T', your image will get more and more precise.

You'll also see that it's getting more and more time to do it. Well, that's because you're giving him more and more job to do, since it has to iterate enough time for each point in the image to see where it's going. Not an easy task.

Still here? Great! What about the others set that are available with this program? Well, let's talk about the Julia set.

The concept is the same, except that this time, we're going to have a fixed value for c, and then check if the iterations blow up for every value of z.

Let's take an example. You can launch the program with the Julia set parameter ('J'). It is set on a value, but type 'c' to define the value of c with your pointer. If you put it in the center of the image, then we have :

c = a + ib = 0 + i0 = 0

You'll get a black circle. That's because for c = 0, your function becomes f(z) = z². And as we have seen before, for this function, for z between -1 and 1, iterations stay stable, whereas for other values, it leans towards infinity.

You can browse the image with your pointer, and see what possible shapes you can get with those sets. Pretty cool, right?

That's it for fractals. Hope you get a better understanding of it. Though it's not an easy concept to grasp, it is absolutely fascinating. And beautiful! Have fun and feel free to contact me if there is any problem with the program.
