# Data Insertion and Searching

## Purpose
• ImproveyourproficiencyinCprogrammingandyourdexteritywithdynamicmemoryallocation.\
• Demonstrate understanding of a concrete data structure (linked list).\
• Practice multi-file programming and improve your proficiency in using UNIX utilities.

## Task & Requirements

### Dataset
The dataset comes from the City of Melbourne Open Data website,\
which provides a variety of data about Melbourne that you can explore and visualize online:\
https://data.melbourne.vic.gov.au/ \
The dataset used in this project is a subset of the Business establishment trading name and industry classification 2018 dataset, accessed from: https://data.melbourne.vic.gov.au/Business/Business-establishment-trading-name-and-industry-c/vesm-c7r2

Census year - the year in which surveying was completed (2018)\
Block ID - an ID number to identify city blocks (about 606 in total)\
Property ID - an ID number to identify an individual property\
Base property ID - an ID number to identify a parcel of land (which may contain multiple properties)\
CLUE small area - city area name (e.g., Melbourne CBD)\
Trading name - name of the business located at this property\
Industry (ANZSIC4) code - numeric code to describe the industry in which the business operates\
Industry (ANZSIC4) description - name of the industry corresponding to the code\
x coordinate - longitude of the establishment\
y coordinate - latitude of the establishment\
Location - location as a (lat,long) pair (used for visualization)

### Implementation Details
Your Makefile should produce an executable program called dict. \
This program should take two command line arguments: \
(1) the name of the data file used to build the dictionary,\
and (2) the name of an output file.

Your dict program should:\
• Construct a linked list to store the information contained in the data file specified in the command line argument. Each record (row) should be stored in a separate Node.\
• Search the linked list for records, based on keys. The keys will be read in from stdin, i.e. from the screen. Remember that the entries in the file do not necessarily have unique keys, so your search must locate all keys matching the search key, and output all the data found.\
• Your program will look up each key and output the information (the data found) to the output file specified by the second command line parameter. If the key is not found in the tree, you must output the word NOTFOUND.

---
### Command Line
`mdict datafile outputfile < keyfile`

### Example Output
#### _records in output.txt_
In a Rush Espresso −−>Census year: 2018 || Block ID: 44 || Property ID: 105956 ||\
Base property ID: 105956 || CLUE small area: Melbourne (CBD) || Industry (ANZSIC4) code: 4511 ||\
Industry (ANZSIC4) description: Cafes and Restaurants || x coordinate: 144.96174 ||\
y coordinate: -37.81561 b|| Location: (-37.81560561, 144.9617411) ||

In a Rush Espresso −− > Census year: 2018 || Block ID: 1101 || Property ID: 108973 ||\
Base property ID: 108973 || CLUE small area: Docklands || Industry (ANZSIC4) code: 4511 ||\
Industry (ANZSIC4) description: Cafes and Restaurants || x coordinate: 144.95223 ||\
y coordinate: -37.81761 || Location: (-37.81761044, 144.9522269) ||

Tim Hortons −− > NOTFOUND

---
_*more details in [project specification](https://github.com/is0xjh25/data-insertion-searching/blob/main/assignment1.pdf)._

