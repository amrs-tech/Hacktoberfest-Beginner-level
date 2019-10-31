module ComposeRelationluislreyes where

-- A Binary Relation is a list of pairs of any types
type BinaryRelation a b = [(a,b)]

-- Composing a BinaryRelation consists of producing an output comprised of the relations
-- Of two Binary Relations, ex. (a,b) and (b,c) will produce (a,c)
compose :: Eq b => (BinaryRelation a b) -> (BinaryRelation b c) -> (BinaryRelation a c)
compose a b = [ (x,z) | (x,j) <- a, (k,z) <- b, j == k ]

-- For example, compose [("chicken", "tender")] [("tender","care")] will produce [("chicken","care")]!