import openai

def complete(prompt):
    response = openai.Completion.create(
        engine="gpt-oss-120b",
        prompt=prompt,
        max_tokens=150,
        n=1,
        stop=None,
        temperature=0.7,
    )

    return response.choices[0].text.strip()

def chat(prompt):
    response = openai.ChatCompletion.create(
        model="gpt-oss-120b",
        messages=[
            {"role": "user", "content": prompt}
        ]
    )
    return response.choices[0].message.content.strip()
