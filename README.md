BlurParser
==========

Set of classes written on C++ useful for creating simple parsers.

As of the latest commit, the classes included are ready to be used. Some minor
changes might happen, but they can be used to create simple tokenizers and
parsers. 

An example of how to use some of the classes to obtain tokens from a line:

```
#include "MyAutomata.h"
#include "MyKeywordSet.h"
#include "BlurParser/Core/Token.h"
#include "BlurParser/Tokenizer/Tokenizer.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
  /// AbstractAutomata must be subclassed.
  /// KeywordSet might be subclassed or not.
  /// LineFileReader and ErrorKeeper classes can be ommited.
  Tokenizer tokenizer(new MyAutomata, new MyKeywordSet);
  Token * token = 0;
  string line = "Some line here...";
  
  /// The transitions matrix must be set. Method returns false if
  /// something fails.
  /// Additionally, the AbstractAutomata constructor can take the filename
  /// as a parameter and perform this step upon object creation.
  tokenizer.automata().loadMatrix("path_to_file/transtions_file.txt");
  /// line could come from a different source (a file, for example)
  /// Set a LineFileReader object on the tokenizer if that's the case.
  tokenizer.setLine(line);
  token = tokenizer.getToken();
  while (token != 0) {
    /// Do something with token here.
    delete token;
    token = tokenizer.getToken();
  }
  
  return 0;
}
```

More examples and documentation will be added later.
