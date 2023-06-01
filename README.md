# stog - static blog post generator
This is a tool to generate simple, static HTML pages.


## Installation
To install stog run the following command (if necessary as root):

`make clean install`


## Input format
Title and page content are separated by the first occurence of '|' in the input
string.

The content is wrapped inside a <p> element. You can use other HTML elements in
the input. The input string must not contain linebreaks.

### Example

`This is my page title|This is my content</p><p>I can end the paragraph started by stog and start a new one.`


## Usage
stog takes input from stdin and writes to stdout.

To pipe some input into stog and write it to a HTML file you could use the
following command:

`cat post.txt | stog > post.html`


## Similar projects
This project was inspired by [saait](https://git.codemadness.nl/saait) and
[stagit](https://git.codemadness.nl/stagit)
