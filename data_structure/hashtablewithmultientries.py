# -*- coding: utf-8 -*-

class HashTableException(Exception):

	def __init__(self, error = 'hash table error'):
		Exception.__init__(self, error)


class HashTable(object):

	def __init__(self, default_size = 16):
		self.size = 0
		self.table_size = default_size
		self.bucket = [None] * self.table_size

	def __len__(self):
		return self.size

	def __setitem__(self, key, value):
		if self.size / self.table_size > 1.5:
			self.up_size()
		h = hash(key) % self.table_size
		if self.bucket[h] is None:
			self.bucket[h] = []
		# for pair in self.bucket[h]:
		# 	if pair[0] == key:
		# 		pair[1] = value
		# 		return

		self.bucket[h].append([key, value])
		self.size += 1


	def __getitem__(self, key):
		h = hash(key) % self.table_size
		if self.bucket[h] is None:
			raise HashTableException(error = 'key error')
		for pair in self.bucket[h]:
			if pair[0] == key:
				return pair[1]
		raise HashTableException(error = 'not found')

	def __delitem__(self, key):

		if self.size / self.table_size < 0.25:
			self.down_size()
		h = hash(key) % self.table_size
		if self.bucket[h] is None:
			raise HashTableException(error = 'not found')
		for i, pair in enumerate(self.bucket[h]):
			if pair[0] == key:
				del self.bucket[h][i]
				self.size -= 1
				return
		raise HashTableException(error = 'key error')


	def items(self):
		for i in self.bucket:
			if i is None:
				continue
			yield('************')
			for pair in i:
				yield pair

	def isempty(self):
		return self.size == 0

	def up_size(self):
		target_size = 2 * self.table_size
		new_bucket = [None, ] * target_size
		for i in range(target_size):
			new_bucket[i] = [p for p in self.bucket[int(i % self.table_size)] if hash(p[0]) % target_size == 1]

		self.table_size = target_size
		self.bucket = new_bucket


	def down_size(self):
		target_size = int(self.table_size / 2)
		new_bucket = [None, ] * target_size
		for i in range(self.table_size):
			if not self.bucket[i]:
				continue
			index = i % target_size
			if not new_bucket[index]:
				new_bucket[index] = []
			new_bucket[index].extend(self.bucket[i])
		self.table_size = target_size
		self.bucket = new_bucket


def test():
	h = HashTable()
	print(h.isempty())
	print(len(h))
	for  i in range(14,21):
		h[i] = "{}xxxxx".format(i)

	h[33] = '33xxxxx'
	del h[17]
	print(h.isempty())
	print(len(h))

	for i in h.items():
		print(i)	

if __name__ == '__main__':
	test()





	