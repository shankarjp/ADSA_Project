
/* Creating and Updating a Base Trie*/

const Trie = require("merkle-patricia-tree").BaseTrie; // We import the library required to create a basic Merkle Patricia Tree

var trie = new Trie(); // We create an empty Patricia Merkle Tree
console.log("Empty trie root (Bytes): ", trie.root); // The trie root (32 bytes)

async function test() {
  await trie.put("testKey", "testValue"); // We update (using "put") the trie with the key-value pair "testKey": "testValue"
  const value = await trie.get("testKey"); // We retrieve (using "get") the value at key "testKey"
  console.log("Value (Bytes): ", value);
  console.log("Value (String): ", value.toString());
  console.log("Updated trie root:", trie.root); // The new trie root (32 bytes)
}

test();
