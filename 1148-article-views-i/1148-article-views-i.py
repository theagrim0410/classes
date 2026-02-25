import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    ans = views[views["author_id"] == views["viewer_id"]]
    ans = ans[["author_id"]].drop_duplicates().sort_values("author_id")
    ans = ans.rename(columns = {"author_id" : "id"})

    return ans