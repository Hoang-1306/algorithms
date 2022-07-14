
def set_of_values_less_than_x(items, val):
    items.sort(reverse=True)
    n = len(items)
    all_basket = []
    while True:

        if len(items) == 0:
            break
        #  create basket
        basket = []

        def add_items_to_basket(basket, items):

            def check(item, pivot, basket, val):
                # check value item[pivot] see if it exceeds "val" no
                if item[pivot] > val:
                    items.pop(pivot)

                # Check whether the basket is overloaded or not
                if sum(basket)+item[pivot] <= val:
                    return True
                return False

            pivot = 0
            while True:
                if pivot >= len(items):
                    break

                if check(items, pivot, basket, val):
                    basket.append(items[pivot])
                    items.pop(pivot)
                    pivot = pivot - 1
                pivot = pivot + 1
            return basket

        basket = add_items_to_basket(basket, items)

        all_basket.append(basket)
    return all_basket


if __name__ == "__main__":
    items = [9, 7, 7, 39, 8, 4, 3, 6, 23, 13, 5, 45]
    print(set_of_values_less_than_x(items, 20))
