# Vim Notes

```
h j k l - cursor movements (left down up right)
g + j/k - navigate wrapped lines
{ - jump paragraph down
} - jump paragraph up
ctrl-u - move up
ctrl-d - move down
gg - move to top of file
g_ - move to end of line (non-whitespace)
^ - move to start of line (non-whitespace)
10gg - move to line 10
G - move to end of file
% jump to matching ({[]})
O - new line (above)
o - new line (underneath)
i - insert at cursor
I - insert text at the beginning of a line
A - insert text at the end of a line
a - append after cursor
gi - return where you last made a change

in insert mode:
ctrl-h
ctrl-w remove word
ctrl-u remove line


w/W - move to beginning of word/Word (forwards)
b/B - move to beginning of word/Word (backwards)
e/E - move to end of word/Word (forwards)
ge/gE - move to end of word/Word (backwards)
t/T - find till something inline forwards/backwards
f/F - find in line, forwards used with ; and , forwards/backwards
ctrl-o - return to certain location
/pattern - find pattern forwards, use with n,N
?pattern - find pattern backwards, use with n,N

d2w - delete 2 words
D - delete everything from cursor to end of line
dd - delete line (copies it as well)

c - change word (delete + insert)
C - change line
ci/ca - change inner / around, aka with whitespaces
ci" - change words inside " "
. - repeat last action
ciw - change word with cursor anywhere on word
caw - change word and destroy surround ([{}])

y - copy
yy - copy line
p - paste
g~ - switch case (use it with iw)
>/< - add indentation
= - formats code

short-hand operators
x / dl - deletes character 
X / dh - deletes character before cursor
s / ch- deletes character under cursor and puts you into insert


Visual mode:
v - character-wise visual mode
V - for line-wise visual mode
ctrl-v - for blockwise visual mode (operating on a chunk at the same position)

Search and replace:
/ - search for pattern, use n and N to move back and forth

Change and repeat:
/ - search for pattern
cgn - change the next search hit
<insert replacement> - then hit esc to finish
4. - repeat replacement for next 4 occurrences OR press n to continue searching

Find exact word:
/\<your_exact_word\>

Pasting:
p/P - depending on copied word/line, paste below/right or paste above / left
yy - yank whole line



Vim Registers: storage for copy/paste/delete
" - the unnamed/default register
a-z - named registers 
0 - yank register, stores the last thing you yanked
1-9 - cut registers, stores the last 9 things you cut with delete/change 
:reg - view contents in your register
"ayy - yank line to register a
"ap - paste from register
"by2w - yank 2 words from cursor
"b2p - paste twice from register


my own mappings:
    enabled ctrl-hjkl in insert mode


i