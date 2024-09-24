# france-ioi
This a repo where I store my submissions to te website france-ioi for competitive programming training.

## Tips
In the following paragraphs are some tips I use when programming in C++ with Linux for competitive programming.
### gdb .gdbinit config file and macros
The `~/.gdbinit` file can stores macros for gdb. Below is an example of such a macro :
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
> [!NOTE]
> The colon (`:`) in the command above is from vim prompt in command mode.

### ctags
A ctags command adapted to C++ :
```bash
ctags -R --kinds-C++=+{prototype}{label}{local} .
```

### vim
My .vimrc file for C++ development:
```vimrc
:set number
:set ts=2
:syntax on
set tags=./tags,tags;$HOME
set shiftwidth=2   
set autoindent    
set smartindent   
set scrolloff=10   
syntax on 

```
