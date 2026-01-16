# france-ioi
This a repo where I store my submissions to te website france-ioi for competitive programming training.

## C++ code template
Here follows a small template for competitive programming with some optimization for I/O on stdin/stdout:
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	return 0
}
```

## Tips
In the following paragraphs are some tips I use when programming in C++ with Linux for competitive programming.
### gdb .gdbinit config file and macros
The `~/.gdbinit` file can stores macros for gdb. Below is an example of such a macro to display a char [][] array:
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
The following script applies to a vector&lt;vector&lt;char&gt;&gt; : 
```gdbinit
python
import gdb

class PrintCharMatrix(gdb.Command):
    """Print vector<vector<char>> as a matrix.
       Usage: printCharMatrix <vec>
       Automatically detects number of rows and columns.
    """

    def __init__(self):
        super(PrintCharMatrix, self).__init__(
            "printCharMatrix", gdb.COMMAND_USER
        )

    def get_vector_start(self, vec):
        """Return pointer to start of a std::vector"""
        try:
            # Try libstdc++ internal field
            return vec["_M_impl"]["_M_start"]
        except gdb.error:
            try:
                # Try libc++ internal field
                return vec["__begin_"]
            except gdb.error:
                raise gdb.GdbError("Cannot find vector start pointer.")

    def get_vector_size(self, vec):
        """Return size of a std::vector"""
        try:
            # libstdc++
            return int(vec["_M_impl"]["_M_finish"] - vec["_M_impl"]["_M_start"])
        except gdb.error:
            try:
                # libc++
                return int(vec["__end_"] - vec["__begin_"])
            except gdb.error:
                raise gdb.GdbError("Cannot determine vector size.")

    def invoke(self, arg, from_tty):
        argv = gdb.string_to_argv(arg)
        if len(argv) != 1:
            print("Usage: printCharMatrix <vec>")
            return

        vec = gdb.parse_and_eval(argv[0])
        rows = self.get_vector_size(vec)

        outer_ptr = self.get_vector_start(vec)

        for i in range(rows):
            row = (outer_ptr + i).dereference()
            cols = self.get_vector_size(row)
            data = self.get_vector_start(row)

            for j in range(cols):
                c = int((data + j).dereference())
                # print(chr(c), end=" " if j + 1 < cols else "")
                print(chr(c), end="")
            print()

PrintCharMatrix()
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
