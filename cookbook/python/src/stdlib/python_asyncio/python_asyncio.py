import asyncio

async def f(n):
    print(f'Waiting {n}s...')
    # The await keyword causes asyncio.sleep(n) to execute, waits for the code to be completed, and returns a result.
    # The await keyword is only valid inside a coroutine. 
    await asyncio.sleep(n)
    print('Finished')

if __name__ == '__main__':

    asyncio.run(f(1))
