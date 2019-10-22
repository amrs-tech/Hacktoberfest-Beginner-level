# This program samples the use of tuples in Python
# Tuples are used to hold together multiple objects. 
# Think of them as similar to lists, but without the extensive functionality that the list class gives you. 
# One major feature of tuples is that they are immutable like strings i.e. you cannot modify tuples

colors = ('red', 'green', 'blue')

print('Number of colors in the color_set_1 are: ', len(colors))

new_colors = 'voilet', 'yellow', colors    # parentheses not required but are a good idea

print('Number of colors in color_set_2 are', len(new_colors))

print('All colors in the color_set_2 are', new_colors)

print('Colors from color_set_1 are', new_colors[2])

print('Last color brought from color_set_1 is', new_colors[2][2])

print('Number of colors in the colors_set_2 is',
      len(new_colors)-1+len(new_colors[2]))
