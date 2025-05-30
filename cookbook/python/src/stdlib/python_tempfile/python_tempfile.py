import os
import tempfile

# Beware! # Don't use tempfile.NamedTemporaryFile under Windows: https://bugs.python.org/issue14243
# Also, use mkstemp correctly (Linux and Windows): https://www.logilab.org/blogentry/17873
fd, temp_name = tempfile.mkstemp()
print(temp_name)

with open(temp_name, encoding='utf-8') as f:
    content = f.read()
os.close(fd)
os.unlink(temp_name)

print(content)
