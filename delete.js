/* Deleting a Key-Value Pair from a Trie*/

const Trie = require("merkle-patricia-tree").BaseTrie; // We import the library required to create a basic Merkle Patricia Tree

var trie = new Trie(); // We create an empty Patricia Merkle Tree
console.log("Empty trie root: ", trie.root); // The trie root

async function test() {
  await trie.put("testKey", "testValue"); // We update (using "put") the trie with the key-value pair "testKey": "testValue"
  var value = await trie.get("testKey"); // We retrieve (using "get") the value at key "testKey"
  console.log("Value (String): ", value.toString()); // We retrieve our value
  console.log("Updated trie root:", trie.root); // The new trie root

  await trie.del("testKey");
  value = await trie.get("testKey"); // We try to retrieve the value at (deleted) key "testKey"
  console.log('Value at key "testKey": ', value); // Key not found. Value is therefore null.

  console.log("Trie root after deletion:", trie.root); // Our trie root is back to its initial value
}

test();
