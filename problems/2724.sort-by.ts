// @leetcode id=2724 questionId=2860 slug=sort-by lang=typescript site=leetcode.com title="Sort By"
type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Fn = (value: JSONValue) => number

function sortBy(arr: JSONValue[], fn: Fn): JSONValue[] {
    return [...arr].sort((a, b) => fn(a) - fn(b));
};
