#!/usr/bin/python3
"""Module that defines/calculate the perimeter of an island in a grid."""


def neighbors_max_water(grid, y, z):
    """Function that returns the perimeter of the island described in grid."""

    fil = 0

    if y <= 0 or not grid[y - 1][z]:
        fil += 1
    if z <= 0 or not grid[y][z - 1]:
        fil += 1
    if z >= len(grid[y]) - 1 or not grid[y][z + 1]:
        fil += 1
    if y >= len(grid) - 1 or not grid[y + 1][z]:
        fil += 1

    return fil


def island_perimeter(grid):
    """Returns the perimeter of the island in grid."""

    perimeter = 0
    y = 0
    while y < len(grid):
        z = 0
        while z < len(grid[y]):
            if grid[y][z]:
                perimeter += neighbors_max_water(grid, y, z)
            z += 1
        y += 1

    return perimeter
