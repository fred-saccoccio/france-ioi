# france-ioi
This a repo where I store my submissions to te website france-ioi for competitive programming training.

## Tips
### gdb .gdbinit config file

### gdb macros

### Copy the whole text in the clipboard from vim
```bash
:%w !xclip -sel c
```
NOTE : The colon in the command above is from vim prompt in command mode.

### ctags
A ctags command adapted to C++ :
```bash
ctags -R --kinds-C++=+{prototype}{label}{local} .
```

### vim
My .vimrc file for C++ development:
```vimrc
" disable vi compatibility (emulation of old bugs)
set nocompatible
" use indentation of previous line
set autoindent
" use intelligent indentation for C
set smartindent
```
