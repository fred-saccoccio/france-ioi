# france-ioi
This a repo where I store my submissions to te website france-ioi for competitive programming training.

## Tips
### gdb .gdbinit config file and macros
The ~/.gdbinit file can stores macros for gdb. Below is an example of such a macro :
```gdbinit
define printCharMatrix 
  set $arr = $arg0
	set $lines = $arg1
	set $cols = $arg2
	set $i = 0
	while $i < $lines
		set $j = 0
		while $j < $cols
			printf "%c", $arr[$i][$j]
			if $j != $cols - 1
				printf " "
				end
			set $j = $j + 1
			end
			printf "\n"
			set $i = $i + 1
		end
```

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
