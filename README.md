# Logistic Map

## Background

The logistic mapping is an easy recurrence relation that can be used to explore chaos.

This is a small program that generates the output of the relation (shown below), and then plots it.

![Logistic Equation](http://imgur.com/wpnp2CO.jpg)


![Periodic Behavior](http://imgur.com/7wK159m.jpg)


## Explanation

The code can be broken into plotting code and the math code.

### Plotting Code
I used gnuplot to plot the time series. C++ is notorious for having crappy, hard to use plotting libraries. The decision to use gnuplot is questionable, but I'm not going to re-write it.

We open a pipe to gnuplot, see [here](https://github.com/ThomasThelen/Logistic-Map/blob/master/main.cpp#L9) and pipe the data to the process in the [Plot](https://github.com/ThomasThelen/Logistic-Map/blob/master/main.cpp#L40) method.


### Math Code
The math is fairly simple. The [LogisticMap](https://github.com/ThomasThelen/Logistic-Map/blob/master/main.cpp#L11) class represents a logistic map. 

The heavy lifting is done in `void LogisticMap::ComputeX()`, which just computes the successive value by the rules of the logistic mapping.


## Use

Chances are, you're looking at this as an example of how to impliment the logistic map. You're probably not here to actually run this code. But. If you want to, just create the `LogisticMap` object, call `ComputeX` on it, and then optionally plot with `Plot`.
