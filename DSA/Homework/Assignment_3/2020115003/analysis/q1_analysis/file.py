import matplotlib.pyplot as plt

# line 1 points
x1 = [0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9]
y1 = [1,1,1,1,1,1,1,1,1]
# plotting the line 1 points
plt.plot(x1, y1, label = "separate chaining")

# line 2 points
x2 = [0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9]
y2 = [1.045,1.097,1.190,1.362,1.735,2.783,7.865,62.254,148.306]
# plotting the line 2 points
plt.plot(x2, y2, label = "linear probing")

#line 3 points
x3 = [0.1,0.2,0.3,0.4,0.5]
y3 = [1.025,1.075,1.123,1.235,1.513]

# plotting the line 3 points
plt.plot(x3, y3, label = "quadratic probing")

# naming the x axis
plt.xlabel('x - axis')
# naming the y axis
plt.ylabel('y - axis')
# giving a title to my graph
plt.title('Probing Analysis')

# show a legend on the plot
plt.legend()

# function to show the plot
plt.show()
