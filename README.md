[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.

## Testing Reasoning

test 1, insert
I tested inserting items into the inventory. First I added 4 normal products and checked the size increased correctly.  
why: to make sure normal insertions work and the inventory counts correctly.  

Then I added over 100 more products to make sure the array resizes when it gets bigger than the default capacity.  
why: to test the edge case where the inventory grows beyond the starting array size, so the dynamic resizing works.  

test 2, find
I tested finding products by their ID. First I looked up the 4 products I added to make sure the right one comes back.  
why: to check that the find function correctly returns existing products.  

Then I tried IDs that don’t exist or are blank to make sure the function returns nothing for invalid input.  
why: to make sure the function handles edge cases and doesn’t crash or return wrong items.  

test 3, print/list by category
I tested printing/listing items by category. First I checked that each product shows up under the correct category, even if it has multiple categories separated by '|'.  
why: to verify that categories are parsed correctly and products are listed accurately.  

Then I tried categories that don’t exist or are blank to make sure it handles those correctly and prints 0.  
why: to check edge cases where the category isn’t found, so the program responds correctly without crashing.  
