function deepClone(target, m = new Map()) {
  if (typeof target === 'object') {
    if (m.get(target)) {
      return target
    } else {
      m.set(target, true)
    }

    let cloneTarget = Array.isArray(target) ? [] : {};
    for (const key in target) {
      cloneTarget[key] = deepClone(target[key])
    }
    return cloneTarget
  } else {
    return target
  }
}
